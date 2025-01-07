classdef DualEncoder < matlab.System ...
        & coder.ExternalDependency ...
        & matlabshared.sensors.simulink.internal.BlockSampleTime

    %
    %#codegen
    %#ok<*EMCA>

    properties

    end

    properties(Access = protected)
        Logo = 'IO Device Builder';
    end

    properties (Nontunable)
        Enc0A_Pin = int8(0);
        Enc0B_Pin = int8(0);
        Enc1A_Pin = int8(0);
        Enc1B_Pin = int8(0);
    end

    properties (Access = private)


    end

    methods
        % Constructor
        function obj = DualEncoder(varargin)
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access=protected)
        function setupImpl(obj)
            if ~coder.target('MATLAB')
                coder.cinclude('DualEncoder.h');
                coder.ceval('setupFunctionDualEncoder', (obj.Enc0A_Pin),1, (obj.Enc0B_Pin),1, (obj.Enc1A_Pin),1, (obj.Enc1B_Pin),1);
            end
        end

        function validateInputsImpl(obj,varargin)
            %  Check the input size
            if nargin ~=0

                validateattributes(varargin{1},{'int8'},{'2d','size',[1,1]},'','Reset_Enc0');
                validateattributes(varargin{2},{'int8'},{'2d','size',[1,1]},'','Reset_Enc1');

            end
        end

        function [Enc0_Count,Enc1_Count] = stepImpl(obj ,Reset_Enc0,Reset_Enc1)
            Enc0_Count = int64(zeros(1,1));
            Enc1_Count = int64(zeros(1,1));
            if isempty(coder.target)
            else
                coder.ceval('stepFunctionDualEncoder',coder.ref(Enc0_Count),1,coder.ref(Enc1_Count),1, Reset_Enc0,1, Reset_Enc1,1);
            end
        end

        function releaseImpl(obj)
            if isempty(coder.target)
            else

            end
        end
    end

    methods (Access=protected)
        %% Define output properties
        function num = getNumInputsImpl(~)
            num = 2;
        end

        function num = getNumOutputsImpl(~)
            num = 2;
        end

        function varargout = getInputNamesImpl(obj)
            varargout{1} = 'Reset_Enc0';
            varargout{2} = 'Reset_Enc1';

        end

        function varargout = getOutputNamesImpl(obj)
            varargout{1} = 'Enc0_Count';
            varargout{2} = 'Enc1_Count';
        end

        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end

        function varargout = isOutputFixedSizeImpl(~,~)
            varargout{1} = true;
            varargout{2} = true;
        end

        function varargout = isOutputComplexImpl(~)
            varargout{1} = false;
            varargout{2} = false;
        end

        function varargout = getOutputSizeImpl(~)
            varargout{1} = [1,1];
            varargout{2} = [1,1];
        end

        function varargout = getOutputDataTypeImpl(~)
            varargout{1} = 'int64';
            varargout{2} = 'int64';
        end

        function maskDisplayCmds = getMaskDisplayImpl(obj)
            outport_label = [];
            num = getNumOutputsImpl(obj);
            if num > 0
                outputs = cell(1,num);
                [outputs{1:num}] = getOutputNamesImpl(obj);
                for i = 1:num
                    outport_label = [outport_label 'port_label(''output'',' num2str(i) ',''' outputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            inport_label = [];
            num = getNumInputsImpl(obj);
            if num > 0
                inputs = cell(1,num);
                [inputs{1:num}] = getInputNamesImpl(obj);
                for i = 1:num
                    inport_label = [inport_label 'port_label(''input'',' num2str(i) ',''' inputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            icon = 'DualEncoder';
            maskDisplayCmds = [ ...
                ['color(''white'');',...
                'plot([100,100,100,100]*1,[100,100,100,100]*1);',...
                'plot([100,100,100,100]*0,[100,100,100,100]*0);',...
                'color(''blue'');', ...
                ['text(38, 92, ','''',obj.Logo,'''',',''horizontalAlignment'', ''right'');',newline],...
                'color(''black'');'], ...
                ['text(52,50,' [''' ' icon ''',''horizontalAlignment'',''center'');' newline]]   ...
                inport_label ...
                outport_label
                ];
        end

        function sts = getSampleTimeImpl(obj)
            sts = getSampleTimeImpl@matlabshared.sensors.simulink.internal.BlockSampleTime(obj);
        end
    end

    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end

        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'DualEncoder';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            coder.extrinsic('matlabshared.sensors.simulink.internal.getTargetHardwareName');
            coder.extrinsic('matlabshared.sensors.simulink.internal.getTargetSpecificFileLocationForSensors');
            coder.extrinsic('which');
            coder.extrinsic('error');
            coder.extrinsic('message');
  
            buildInfo.addIncludePaths(pwd);
            addSourceFiles(buildInfo,'ESP32Encoder.cpp',pwd);
            addSourceFiles(buildInfo,'DualEncoder.cpp',pwd);

        end
    end
end
